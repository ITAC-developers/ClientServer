using ITACmessendgerMVVM_wpf_.Models;
using ITACmessendgerMVVM_wpf_.Views;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace ITACmessendgerMVVM_wpf_.ViewModels
{
    internal class MessendgerWindowViewModel : INotifyPropertyChanged
    {
        public client Client { get; set; }
        
        public Authorization loginForm { get; set; }
        private string messege;

        public string Messege
        {
            get { return messege; }
            set
            {
                messege = value;
                OnPropertyChanged("Messege");
            }
        }
       // public ICommand Messenger_LoadCommand { get;private set; }
       //public ICommand Messenger_CloseCommand { get;private set; }
        public MessendgerWindowViewModel()
        {
            //authorizateForm AForm = new authorizateForm();
         //   Messenger_LoadCommand = new messengerCommands(LoginWindowShow);
            loginForm = new Authorization();
            client Client = new client();
            Client.HostName = "127.0.0.1";
            Client.PortServer = 8005;
            Client.connectToSetver();
            if (Client.IsConnected) { Messege = "is connected"; }
            else { Messege = "not connected"; }
            Client.sendMsg("main window");
            loginForm.Show();
            
           // Client.getAnswer();

        }

        private void LoginWindowShow(object obj)

        {
           // Authorization loginForm = new Authorization();
           // loginForm.Show();
        }

        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string propertyData)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
    }
}
