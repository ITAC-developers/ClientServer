using ITACmessendgerMVVM_wpf_.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ITACmessendgerMVVM_wpf_.ViewModels
{
    public class MainWindowViewModel : INotifyPropertyChanged
    {
        authorizateForm authoForm;
        public authorizateForm AuthoForm { get; set; }
        public MainWindowViewModel()
        {
            AuthoForm = new authorizateForm();
            AuthoForm.Login = "andreysp";
            AuthoForm.Password = "Password";
            AuthoForm.IsAuthirizated = false;
            AuthoForm.IsRemembered = true;
            AuthoForm.MsgHint = "Server not founded";
        }
        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string propertyData)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
    }
}
