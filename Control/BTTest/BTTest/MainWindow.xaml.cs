using InTheHand.Net;
using InTheHand.Net.Bluetooth;
using InTheHand.Net.Sockets;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace BTTest
{
    /// <summary>
    /// Lógica de interacción para MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public const string AddressMaster = "";
        public const string AddressSlave = "";
        public string PairingCode { get; set; }

        private static BluetoothEndPoint EP = new BluetoothEndPoint(BluetoothAddress.Parse(AddressSlave), BluetoothService.BluetoothBase);
        private static BluetoothClient BC = new BluetoothClient(EP);

        private static BluetoothDeviceInfo BTDevice = new BluetoothDeviceInfo(BluetoothAddress.Parse(AddressMaster));

        private static NetworkStream stream = null;

        public MainWindow()
        {
            InitializeComponent();

            
        }

        private void Conect()
        {
            if (BluetoothSecurity.PairRequest(BTDevice.DeviceAddress, "MY_PAIRING_CODE"))
            {
                //log pair OK

                if (BTDevice.Authenticated)
                {
                    //log auth ok

                    BC.SetPin("MY_PAIRING_CODE");
                    BC.BeginConnect(BTDevice.DeviceAddress, BluetoothService.SerialPort, new AsyncCallback(Connect), BTDevice);
                }
                else
                {
                    //log auth fail
                }
            }
            else
            {
                // log pair fail
            }
        }

        private static void Connect(IAsyncResult result)
        {
            if (result.IsCompleted)
            {
                // client is connected now :)
                //log BC.Connected;
                stream = BC.GetStream();

                if (stream.CanRead)
                {
                    byte[] getBuffer = new byte[1024];
                    StringBuilder msg = new StringBuilder();
                    int numberOfBytesRead = 0;

                    do
                    {
                        numberOfBytesRead = stream.Read(getBuffer, 0, getBuffer.Length);
                        for (int i = 0; i < numberOfBytesRead; i++)
                            msg.AppendFormat("0x{0:X2} ", getBuffer[i]);

                    } while (stream.DataAvailable);
                }
            }
        }
    }
}
