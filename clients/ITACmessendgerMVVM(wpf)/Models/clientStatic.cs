using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ITACmessendgerMVVM_wpf_.Models
{
    static public class clientStatic
    {
        static string hostName = "127.0.0.1";
        static public string HostName
        {
            get { return hostName; }
            set { hostName = value; }
        }
        static int portServer = 8005;
        static public int PortServer 
        {
            get { return portServer; }
            set { portServer = value; }
        }
        static string answer;
        static public string Answer
        {
            get { return answer; }
            private set { answer = value; } 
        }
        static IPEndPoint tcpEndPoint;
        static Socket tcpSocket;
        static bool isConnected=false;
        static public bool IsConnected 
        {
            get { return isConnected; }
            private set { isConnected = value; }
        }
        static public void connectToSetver()
        {
           try
           {
                tcpEndPoint = new IPEndPoint(IPAddress.Parse(hostName), portServer);
                tcpSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                tcpSocket.Connect(tcpEndPoint);
                isConnected = tcpSocket.Connected;
                answer = "Server found";
           }
           catch (Exception ex)
           { 
                isConnected = false;
                answer = "Server not found"; //TODO: make loger
           }
        }

        static public void sendMsg(string msg)
        {   
            var data = Encoding.UTF8.GetBytes(msg);
            if (tcpSocket.Connected)
            tcpSocket.Send(data);
        }

        static public void getAnswer ()
        {
            var buffer = new byte[1024];
            var size = 0;
            var answerServer = new StringBuilder ();
            
            do
            {
                size = tcpSocket.Receive (buffer);
                answerServer.Append (Encoding.UTF8.GetString (buffer, 0, size));
            }
            while (tcpSocket.Available > 0);
            answer=answerServer.ToString ();
        }

        static public void clientOff()
        {
            tcpSocket.Shutdown(SocketShutdown.Both);
            tcpSocket.Close();
        }
    }
}
