using Microsoft.Win32;
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
using ITAC_WinClient.Models;

namespace ITAC_WinClient
{
    /// <summary>
    /// Interaction logic for Option.xaml
    /// </summary>
    public partial class Option : Window
    {
        //func validate dugit in fields

        private void ValidateIsNumeric(TextCompositionEventArgs e)
        {
            int result;

            if (!(int.TryParse(e.Text, out result)))
            {
                e.Handled = true;
            }
        }
        
        public ConfigurationStruct ConfigClient;

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

        private void BrowseButton_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog browseButton = new OpenFileDialog();
            browseButton.Filter = "Config files (*.ifc)|*.ifc";

            if (browseButton.ShowDialog() == true)
                PathSetFile.Text = browseButton.FileName;
        }

        private void FromFileRadio_Checked(object sender, RoutedEventArgs e)
        {
            PathSetFile.IsEnabled = true;
            BrowseButton.IsEnabled = true;
            HostField.IsEnabled = false;
            PortField.IsEnabled = false;
            OptionsClient.IsEnabled = false;
        }

        private void ManualRadio_Checked(object sender, RoutedEventArgs e)
        {
            PathSetFile.IsEnabled = false;
            BrowseButton.IsEnabled = false;
            HostField.IsEnabled = true;
            PortField.IsEnabled = true;
            OptionsClient.IsEnabled = true;
        }

        private void HistoryDayStorage_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            ValidateIsNumeric(e);
        }

        private void PortField_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            ValidateIsNumeric(e);
        }

        private void SaveSettingButton_Click(object sender, RoutedEventArgs e)
        {
            ConfigClient.nameConfig = "config.ifc";
            HostField.Text = ConfigClient.host;
            PortField.Text = ConfigClient.port;
            ConfigClient.host = HostField.Text;

        }
    }
}
