using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace ITAC_WinClient
{
    /// <summary>
    /// Interaction logic for WinWork.xaml
    /// </summary>
    public partial class WinWork : Window
    {
        public WinWork()
        {
            InitializeComponent();
        }

        private void WindowMessenger_Closed(object sender, EventArgs e)
        {
            //MainWindow mainWindow = new MainWindow();
            this.Owner.Show();
            //mainWindow.Show();
        }
    }
}
