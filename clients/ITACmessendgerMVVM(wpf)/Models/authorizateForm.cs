using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ITACmessendgerMVVM_wpf_.Models
{
    public class authorizateForm : INotifyPropertyChanged
    {
        string login;
        string password;
        bool isAuthirizated;
        bool isRemembered;
        string msgHint;
        public string Login {
            get { return login; }
            set {
                login = value;
                OnPropertyChanged("Login");
                }
        }
        public string Password
        {
            get { return password; }
            set
            {
                password = value;
                OnPropertyChanged("Password");
            }
        }
        public string MsgHint
        {
            get { return msgHint; }
            set
            {
                msgHint = value;
                OnPropertyChanged("MsgHint");
            }
        }

        public bool IsAuthirizated
        {
            get { return isAuthirizated; }
            set
            {
                isAuthirizated = value;
                OnPropertyChanged("IsAuthirizated");
            }
        }
        public bool IsRemembered
        {
            get { return isRemembered; }
            set
            {
                isRemembered = value;
                OnPropertyChanged("IsRemembered");
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        void OnPropertyChanged(string propertyData)
        { 
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
        
    }
}
