// Updated by XamlIntelliSenseFileGenerator 4/16/2022 5:43:17 PM
#pragma checksum "..\..\Option.xaml" "{8829d00f-11b8-4213-878b-770e8597ac16}" "5D84FCCE977A703A224D954175CBE8E2680B06F330141F33C3718F4798B08786"
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


namespace ITAC_WinClient
{


    /// <summary>
    /// Option
    /// </summary>
    public partial class Option : System.Windows.Window, System.Windows.Markup.IComponentConnector
    {

#line default
#line hidden


#line 10 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.GroupBox OptionsServer;

#line default
#line hidden


#line 12 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox PathSetFile;

#line default
#line hidden


#line 13 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button BrowseButton;

#line default
#line hidden


#line 14 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox HostField;

#line default
#line hidden


#line 15 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox PortField;

#line default
#line hidden


#line 16 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label HostLabel;

#line default
#line hidden


#line 17 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label PortLabel;

#line default
#line hidden


#line 29 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.GroupBox OptionsClient;

#line default
#line hidden


#line 31 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label HistoryLabel;

#line default
#line hidden


#line 32 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox HistoryDayStorage;

#line default
#line hidden


#line 36 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button SaveSettingButton;

#line default
#line hidden


#line 37 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.RadioButton FromFileRadio;

#line default
#line hidden


#line 38 "..\..\Option.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.RadioButton ManualRadio;

#line default
#line hidden

        private bool _contentLoaded;

        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent()
        {
            if (_contentLoaded)
            {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/ITAC_WinClient;component/option.xaml", System.UriKind.Relative);

#line 1 "..\..\Option.xaml"
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
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target)
        {
            switch (connectionId)
            {
                case 1:
                    this.WinOptions = ((ITAC_WinClient.Option)(target));

#line 8 "..\..\Option.xaml"
                    this.WinOptions.Closed += new System.EventHandler(this.WinOptions_Closed);

#line default
#line hidden
                    return;
                case 2:
                    this.OptionsServer = ((System.Windows.Controls.GroupBox)(target));
                    return;
                case 3:
                    this.PathSetFile = ((System.Windows.Controls.TextBox)(target));
                    return;
                case 4:
                    this.BrowseButton = ((System.Windows.Controls.Button)(target));

#line 13 "..\..\Option.xaml"
                    this.BrowseButton.Click += new System.Windows.RoutedEventHandler(this.BrowseButton_Click);

#line default
#line hidden
                    return;
                case 5:
                    this.HostField = ((System.Windows.Controls.TextBox)(target));
                    return;
                case 6:
                    this.PortField = ((System.Windows.Controls.TextBox)(target));

#line 15 "..\..\Option.xaml"
                    this.PortField.PreviewTextInput += new System.Windows.Input.TextCompositionEventHandler(this.PortField_PreviewTextInput);

#line default
#line hidden
                    return;
                case 7:
                    this.HostLabel = ((System.Windows.Controls.Label)(target));
                    return;
                case 8:
                    this.PortLabel = ((System.Windows.Controls.Label)(target));
                    return;
                case 9:
                    this.OptionsClient = ((System.Windows.Controls.GroupBox)(target));
                    return;
                case 10:
                    this.HistoryLabel = ((System.Windows.Controls.Label)(target));
                    return;
                case 11:
                    this.HistoryDayStorage = ((System.Windows.Controls.TextBox)(target));

#line 32 "..\..\Option.xaml"
                    this.HistoryDayStorage.PreviewTextInput += new System.Windows.Input.TextCompositionEventHandler(this.HistoryDayStorage_PreviewTextInput);

#line default
#line hidden
                    return;
                case 12:
                    this.SaveSettingButton = ((System.Windows.Controls.Button)(target));

#line 36 "..\..\Option.xaml"
                    this.SaveSettingButton.Click += new System.Windows.RoutedEventHandler(this.SaveSettingButton_Click);

#line default
#line hidden
                    return;
                case 13:
                    this.FromFileRadio = ((System.Windows.Controls.RadioButton)(target));

#line 37 "..\..\Option.xaml"
                    this.FromFileRadio.Checked += new System.Windows.RoutedEventHandler(this.FromFileRadio_Checked);

#line default
#line hidden
                    return;
                case 14:
                    this.ManualRadio = ((System.Windows.Controls.RadioButton)(target));

#line 38 "..\..\Option.xaml"
                    this.ManualRadio.Checked += new System.Windows.RoutedEventHandler(this.ManualRadio_Checked);

#line default
#line hidden
                    return;
            }
            this._contentLoaded = true;
        }

        internal System.Windows.Window WinOptions;
    }
}

