﻿#pragma checksum "..\..\MainWindow.xaml" "{8829d00f-11b8-4213-878b-770e8597ac16}" "9B1029F6FD0B42FB98F5C07D38AF5679EB6D73F8C3A8687BC7EFBCE67F2946B2"
//------------------------------------------------------------------------------
// <auto-generated>
//     Этот код создан программой.
//     Исполняемая версия:4.0.30319.42000
//
//     Изменения в этом файле могут привести к неправильной работе и будут потеряны в случае
//     повторной генерации кода.
// </auto-generated>
//------------------------------------------------------------------------------

using ITAC_WinClient;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace ITAC_WinClient {
    
    
    /// <summary>
    /// MainWindow
    /// </summary>
    public partial class MainWindow : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 8 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal ITAC_WinClient.MainWindow AuthorizeWindow;
        
        #line default
        #line hidden
        
        
        #line 26 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem Menu;
        
        #line default
        #line hidden
        
        
        #line 31 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem OptionItem;
        
        #line default
        #line hidden
        
        
        #line 36 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.MenuItem ExitItem;
        
        #line default
        #line hidden
        
        
        #line 68 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox LoginField;
        
        #line default
        #line hidden
        
        
        #line 84 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.PasswordBox PasswordField;
        
        #line default
        #line hidden
        
        
        #line 94 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button ToAuthorize;
        
        #line default
        #line hidden
        
        
        #line 105 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label RegistrationLabel;
        
        #line default
        #line hidden
        
        
        #line 117 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label ForgotLabel;
        
        #line default
        #line hidden
        
        
        #line 128 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.CheckBox CheckRemember;
        
        #line default
        #line hidden
        
        
        #line 157 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox DescInfo;
        
        #line default
        #line hidden
        
        
        #line 171 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Image image;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/ITAC_WinClient;component/mainwindow.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\MainWindow.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.AuthorizeWindow = ((ITAC_WinClient.MainWindow)(target));
            return;
            case 2:
            this.Menu = ((System.Windows.Controls.MenuItem)(target));
            return;
            case 3:
            this.OptionItem = ((System.Windows.Controls.MenuItem)(target));
            
            #line 32 "..\..\MainWindow.xaml"
            this.OptionItem.Click += new System.Windows.RoutedEventHandler(this.OptionItem_Click);
            
            #line default
            #line hidden
            return;
            case 4:
            this.ExitItem = ((System.Windows.Controls.MenuItem)(target));
            
            #line 37 "..\..\MainWindow.xaml"
            this.ExitItem.Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click);
            
            #line default
            #line hidden
            return;
            case 5:
            
            #line 42 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_1);
            
            #line default
            #line hidden
            return;
            case 6:
            this.LoginField = ((System.Windows.Controls.TextBox)(target));
            
            #line 78 "..\..\MainWindow.xaml"
            this.LoginField.MouseEnter += new System.Windows.Input.MouseEventHandler(this.TextBox_MouseEnter);
            
            #line default
            #line hidden
            
            #line 79 "..\..\MainWindow.xaml"
            this.LoginField.MouseLeave += new System.Windows.Input.MouseEventHandler(this.TextBox_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 7:
            this.PasswordField = ((System.Windows.Controls.PasswordBox)(target));
            
            #line 91 "..\..\MainWindow.xaml"
            this.PasswordField.MouseEnter += new System.Windows.Input.MouseEventHandler(this.PasswordBox_MouseEnter);
            
            #line default
            #line hidden
            
            #line 92 "..\..\MainWindow.xaml"
            this.PasswordField.MouseLeave += new System.Windows.Input.MouseEventHandler(this.PasswordBox_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 8:
            this.ToAuthorize = ((System.Windows.Controls.Button)(target));
            
            #line 100 "..\..\MainWindow.xaml"
            this.ToAuthorize.Click += new System.Windows.RoutedEventHandler(this.ToAuthorize_Click);
            
            #line default
            #line hidden
            
            #line 102 "..\..\MainWindow.xaml"
            this.ToAuthorize.MouseEnter += new System.Windows.Input.MouseEventHandler(this.ToAutorize_MouseEnter);
            
            #line default
            #line hidden
            
            #line 103 "..\..\MainWindow.xaml"
            this.ToAuthorize.MouseLeave += new System.Windows.Input.MouseEventHandler(this.ToAutorize_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 9:
            this.RegistrationLabel = ((System.Windows.Controls.Label)(target));
            
            #line 114 "..\..\MainWindow.xaml"
            this.RegistrationLabel.MouseEnter += new System.Windows.Input.MouseEventHandler(this.RegistrationLabel_MouseEnter);
            
            #line default
            #line hidden
            
            #line 115 "..\..\MainWindow.xaml"
            this.RegistrationLabel.MouseLeave += new System.Windows.Input.MouseEventHandler(this.RegistrationLabel_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 10:
            this.ForgotLabel = ((System.Windows.Controls.Label)(target));
            
            #line 125 "..\..\MainWindow.xaml"
            this.ForgotLabel.MouseEnter += new System.Windows.Input.MouseEventHandler(this.ForgotLabel_MouseEnter);
            
            #line default
            #line hidden
            
            #line 126 "..\..\MainWindow.xaml"
            this.ForgotLabel.MouseLeave += new System.Windows.Input.MouseEventHandler(this.ForgotLabel_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 11:
            this.CheckRemember = ((System.Windows.Controls.CheckBox)(target));
            return;
            case 12:
            this.DescInfo = ((System.Windows.Controls.TextBox)(target));
            
            #line 167 "..\..\MainWindow.xaml"
            this.DescInfo.Loaded += new System.Windows.RoutedEventHandler(this.DescInfo_Loaded);
            
            #line default
            #line hidden
            return;
            case 13:
            this.image = ((System.Windows.Controls.Image)(target));
            return;
            }
            this._contentLoaded = true;
        }
    }
}
