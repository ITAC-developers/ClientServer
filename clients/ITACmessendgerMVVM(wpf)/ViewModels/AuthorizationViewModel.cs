using ITACmessendgerMVVM_wpf_.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ITACmessendgerMVVM_wpf_.ViewModels
{
    class AuthorizationViewModel : INotifyPropertyChanged
    {
        authorizateForm authoForm;
        public authorizateForm AuthoForm
        {
            get { return authoForm; }
            private set { authoForm = value; }
        }
        public AuthorizationViewModel()
        {
            AuthoForm = new authorizateForm();
            authoForm.Login = "Enter username";
            authoForm.Password = "Password";
            authoForm.IsAuthirizated = false;
            authoForm.IsRemembered = false;
        }
        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string propertyData)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
    }
}
