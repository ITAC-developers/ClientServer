using ITACmessendgerMVVM_wpf_.Models;
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
    class AuthorizationViewModel : INotifyPropertyChanged
    {
        public bool isLogin { get; set; }
        public authorizateForm authoForm { get; set; }
        public client clientLogin { get; set; }
        public ICommand loginCommand { get; private set; }
        public ICommand CloseCommand { get; private set; }
        public AuthorizationViewModel()
        {
            loginCommand = new messengerCommands(login);
            CloseCommand = new messengerCommands(closeLogin);
            authoForm = new authorizateForm();
            authoForm.Login = "Username";
            authoForm.Password = "Password";
            authoForm.IsAuthirizated = false;
            authoForm.IsRemembered = false;
        }

        private void closeLogin(object obj)
        {
            Application.Current.Shutdown();

        }

        private void login(object obj)
        {
           isLogin = true;
        }

        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string propertyData)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
    }
}
