using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace ITACmessendgerMVVM_wpf_.Models
{
    public class client
    {
        string hostName;
        public string HostName
        {
            get { return hostName; }
            set { hostName = value; }
        }
        int portServer;
        public int PortServer 
        {
            get { return portServer; }
            set { portServer = value; }
        }
        string answer;
        public string Answer
        {
            get { return answer; }
            private set { answer = value; } 
        }
        IPEndPoint tcpEndPoint;
        Socket tcpSocket;
        bool isConnected=false;
        public bool IsConnected 
        {
            get { return isConnected; }
            private set { isConnected = value; }
        }
        public void connectToSetver()
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

        public void sendMsg(string msg)
        {   
            var data = Encoding.UTF8.GetBytes(msg);
            if (isConnected)
            tcpSocket.Send(data);
        }

        public void getAnswer ()
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

        public void clientOff()
        {
            tcpSocket.Shutdown(SocketShutdown.Both);
            tcpSocket.Close();
        }
    }
}
