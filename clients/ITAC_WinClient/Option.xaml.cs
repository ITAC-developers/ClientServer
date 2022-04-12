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
    /// Interaction logic for Option.xaml
    /// </summary>
    public partial class Option : Window
    {
        public Option()
        {   
            InitializeComponent();
        }

        private void WinOptions_Closed(object sender, EventArgs e)
        {
           // this.Owner.Show();
        }

        private void SetFromFileRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            PathSetFile.IsEnabled = true;
            BrowseButton.IsEnabled = true;
            HostField.IsEnabled = false;
            PortField.IsEnabled = false;
        }

        private void ManualRadioButton_Checked(object sender, RoutedEventArgs e)
        {
            PathSetFile.IsEnabled = false;
            BrowseButton.IsEnabled = false;
            HostField.IsEnabled = true;
            PortField.IsEnabled = true;
        }
    }
}
