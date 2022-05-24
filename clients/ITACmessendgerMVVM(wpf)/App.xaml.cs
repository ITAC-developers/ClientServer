using ITACmessendgerMVVM_wpf_.Models;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace ITACmessendgerMVVM_wpf_
{
    /// <summary>
    /// Логика взаимодействия для App.xaml
    /// </summary>
    public partial class App : Application
    {
		private void Application_Startup(object sender, StartupEventArgs e)
		{
			locatorWindows lWindows = new locatorWindows();
            
            lWindows.StartupWindow(Windows[0]);
            lWindows.StartupWindow(Windows[1]);
        }
	}
}
