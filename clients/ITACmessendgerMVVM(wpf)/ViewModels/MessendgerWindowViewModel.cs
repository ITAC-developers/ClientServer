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
       // public clientStatic Client { get; set; }
        
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
        public MessendgerWindowViewModel()
        {
            clientStatic.connectToSetver();
            clientStatic.sendMsg("Static send messege\n");
            //loginForm = new Authorization();
            //loginForm.Show();

        }

        private void LoginWindowShow(object obj)

        {
           
        }

        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged(string propertyData)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(propertyData));
        }
    }
}
