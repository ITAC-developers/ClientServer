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
using System.Windows.Media.TextFormatting;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ITAC_WinClient
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string MsgDesc = "Server connected.";
        //private bool isConnected = false;
        public bool isConnected { get; set; }
        public bool isAutorizated { get; set; }

        public MainWindow()
        {
            isConnected = true;
            isAutorizated = false;

            if (!isConnected)
                MsgDesc = "Server not found.";
           
            InitializeComponent();
        }

        private void MenuItem_Click(object sender, RoutedEventArgs e)
        {
            // TODO: Сохранение данных
            // Разрыв соединения с вервером
            Close(); // Window close
        }

        private void MenuItem_Click_1(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("ITAC - Universal client for ITAC messenger.\nVersion 14.6 (beta).\n" +
                            "\nDevelopers:\n"+
                            "1. Igor Moiseev (Product meneger).\n"+
                            "2. Tigran Ghandilyan.\n"+
                            "3. Andrey Spichkin.\n"+
                            "4. Christina Valeeva.\n",
                            "Version 14.6 (beta) Client by ITAC ", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void TextBox_MouseEnter(object sender, MouseEventArgs e)
        {
            DescInfo.Text = "Введите свой логин в поле Login!";
        }

        private void PasswordBox_MouseEnter(object sender, MouseEventArgs e)
        {
            DescInfo.Text = "Введите свой пароль в поле Password!";
        }

        private void ToAutorize_MouseEnter(object sender, MouseEventArgs e)
        {
            DescInfo.Text = "Для авторизации заполните обязательные поля и нажмите Autorization!";
        }

        private void TextBox_MouseLeave(object sender, MouseEventArgs e)
        {
            DescInfo.Text = MsgDesc;
        }

        private void PasswordBox_MouseLeave(object sender, MouseEventArgs e)
        {
            DescInfo.Text = MsgDesc;
        }

        private void ToAutorize_MouseLeave(object sender, MouseEventArgs e)
        {
            DescInfo.Text = MsgDesc;
        }

        private void ForgotLabel_MouseEnter(object sender, MouseEventArgs e)
        {
            ForgotLabel.Foreground = new SolidColorBrush(Color.FromRgb(124, 102, 251));
            DescInfo.Text = "Забыли пароль? Нажмите для востановления.";
        }

        private void ForgotLabel_MouseLeave(object sender, MouseEventArgs e)
        {
            ForgotLabel.Foreground = new SolidColorBrush(Color.FromRgb (0,25,234));
            DescInfo.Text = MsgDesc;
        }

        private void RegistrationLabel_MouseEnter(object sender, MouseEventArgs e)
        {
            RegistrationLabel.Foreground = new SolidColorBrush(Color.FromRgb(124, 102, 251));
            DescInfo.Text = "Еще не зарегистрированны? ";
        }

        private void RegistrationLabel_MouseLeave(object sender, MouseEventArgs e)
        {
            RegistrationLabel.Foreground = new SolidColorBrush(Color.FromRgb(0, 25, 234));
            DescInfo.Text = MsgDesc;
        }

        private void DescInfo_Loaded(object sender, RoutedEventArgs e)
        {
            DescInfo.Text = MsgDesc;
        }

        private void ToAuthorize_Click(object sender, RoutedEventArgs e)
        {   
            if (LoginField.Text=="")
            {
                MsgDesc = "Логин и пароль не могут быть пустыми! Проверте введенные вами данные.";
                LoginField.BorderBrush = new SolidColorBrush(Color.FromRgb(255, 0, 0));
            }
            if (PasswordField.Password == "")
            {
                MsgDesc = "Логин и пароль не могут быть пустыми! Проверте введенные вами данные.";
                PasswordField.BorderBrush = new SolidColorBrush(Color.FromRgb(255, 0, 0));
            }

            this.Hide(); //Hide main window
            WinWork winWork = new WinWork();
            winWork.Owner = this;
            winWork.Show();
            
        }

        private void OptionItem_Click(object sender, RoutedEventArgs e)
        {
            Option optionWindow = new Option();
            // this.Hide();
            optionWindow.Owner = this;
            optionWindow.Show();
        }
    }
}
