using ITACmessendgerMVVM_wpf_.Views;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace ITACmessendgerMVVM_wpf_.Models
{
    internal class locatorWindows
    {
        public List<Window> Windows { get; set; }
        public locatorWindows() 
        { 
            Windows = new List<Window>();
            Authorization authorization = new Authorization();
            MessendgerWindow messendgerWindow = new MessendgerWindow();
            
            Windows.Add(authorization);
            Windows.Add(messendgerWindow);         
        }
        public void StartupWindow(Window startWindow)
        {
            startWindow.Show();
        }
    }
}
