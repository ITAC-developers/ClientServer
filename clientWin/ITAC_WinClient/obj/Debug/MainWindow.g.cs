﻿#pragma checksum "..\..\MainWindow.xaml" "{8829d00f-11b8-4213-878b-770e8597ac16}" "B19B6D975810B6E0C7B04DE7E2D9D885FD341ED7B0D1EB997E1F7EEE14426525"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
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
        
        
        #line 31 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button ToAutorize;
        
        #line default
        #line hidden
        
        
        #line 32 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label RegistrationLabel;
        
        #line default
        #line hidden
        
        
        #line 33 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label ForgotLabel;
        
        #line default
        #line hidden
        
        
        #line 47 "..\..\MainWindow.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox DescInfo;
        
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
            
            #line 20 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click);
            
            #line default
            #line hidden
            return;
            case 2:
            
            #line 22 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.MenuItem)(target)).Click += new System.Windows.RoutedEventHandler(this.MenuItem_Click_1);
            
            #line default
            #line hidden
            return;
            case 3:
            
            #line 29 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.TextBox)(target)).MouseEnter += new System.Windows.Input.MouseEventHandler(this.TextBox_MouseEnter);
            
            #line default
            #line hidden
            
            #line 29 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.TextBox)(target)).MouseLeave += new System.Windows.Input.MouseEventHandler(this.TextBox_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 4:
            
            #line 30 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.PasswordBox)(target)).MouseEnter += new System.Windows.Input.MouseEventHandler(this.PasswordBox_MouseEnter);
            
            #line default
            #line hidden
            
            #line 30 "..\..\MainWindow.xaml"
            ((System.Windows.Controls.PasswordBox)(target)).MouseLeave += new System.Windows.Input.MouseEventHandler(this.PasswordBox_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 5:
            this.ToAutorize = ((System.Windows.Controls.Button)(target));
            
            #line 31 "..\..\MainWindow.xaml"
            this.ToAutorize.MouseEnter += new System.Windows.Input.MouseEventHandler(this.ToAutorize_MouseEnter);
            
            #line default
            #line hidden
            
            #line 31 "..\..\MainWindow.xaml"
            this.ToAutorize.MouseLeave += new System.Windows.Input.MouseEventHandler(this.ToAutorize_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 6:
            this.RegistrationLabel = ((System.Windows.Controls.Label)(target));
            
            #line 32 "..\..\MainWindow.xaml"
            this.RegistrationLabel.MouseEnter += new System.Windows.Input.MouseEventHandler(this.RegistrationLabel_MouseEnter);
            
            #line default
            #line hidden
            
            #line 32 "..\..\MainWindow.xaml"
            this.RegistrationLabel.MouseLeave += new System.Windows.Input.MouseEventHandler(this.RegistrationLabel_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 7:
            this.ForgotLabel = ((System.Windows.Controls.Label)(target));
            
            #line 33 "..\..\MainWindow.xaml"
            this.ForgotLabel.MouseEnter += new System.Windows.Input.MouseEventHandler(this.ForgotLabel_MouseEnter);
            
            #line default
            #line hidden
            
            #line 33 "..\..\MainWindow.xaml"
            this.ForgotLabel.MouseLeave += new System.Windows.Input.MouseEventHandler(this.ForgotLabel_MouseLeave);
            
            #line default
            #line hidden
            return;
            case 8:
            this.DescInfo = ((System.Windows.Controls.TextBox)(target));
            
            #line 47 "..\..\MainWindow.xaml"
            this.DescInfo.Loaded += new System.Windows.RoutedEventHandler(this.DescInfo_Loaded);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}

