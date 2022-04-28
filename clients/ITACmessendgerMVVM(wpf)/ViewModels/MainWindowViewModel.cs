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
        public authorizateForm AuthoForm 
        {
            get { return authoForm; }
            set { authoForm = value; }
        }
        public MainWindowViewModel()
        {
            AuthoForm = new authorizateForm
            {
                Login = "andreysp",
                Password = "Password",
                IsAuthirizated = false,
                IsRemembered = false,
                MsgHint = "Server not founded"
            };
        }
        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string propertyData)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
    }
}
