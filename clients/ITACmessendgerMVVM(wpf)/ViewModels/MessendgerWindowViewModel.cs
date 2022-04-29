using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ITACmessendgerMVVM_wpf_.ViewModels
{
    internal class MessendgerWindowViewModel : INotifyPropertyChanged
    {
        public MessendgerWindowViewModel()
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
