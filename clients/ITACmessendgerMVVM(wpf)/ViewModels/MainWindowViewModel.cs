using ITACmessendgerMVVM_wpf_.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace ITACmessendgerMVVM_wpf_.ViewModels
{
    public class MainWindowViewModel : INotifyPropertyChanged
    {
        
        authorizateForm authoForm;
        client clientITAC;
        public authorizateForm AuthoForm 
        {
            get { return authoForm; }
            private set { authoForm = value; }
        }
        public client ClientITAC
        {
            get { return clientITAC; }
            private set { clientITAC = value; } 
        }
        public MainWindowViewModel()
        {
            clientITAC = new client();
            clientITAC.HostName = "127.0.0.1";
            clientITAC.PortServer = 8005;
            clientITAC.connectToSetver();
                        
            AuthoForm = new authorizateForm();
            authoForm.Login = "andreysp";
            authoForm.Password = "Password";
            authoForm.IsAuthirizated = false;
            authoForm.IsRemembered = false;
            if (clientITAC.IsConnected)
            {
                authoForm.MsgHint = "Server connected";
            }
            else 
            { 
                authoForm.MsgHint = "Server not founded"; 
            }

            clientITAC.sendMsg("login:" + authoForm.Login + ". Password:" + authoForm.Password);
        }
        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string propertyData)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
    }
}
