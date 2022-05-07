using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ITACmessendgerMVVM_wpf_.Models
{
    internal class messengerCommands : ICommand
    {
        Action<object> execute;
        Func<object, bool> canExecute;    
        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public bool CanExecute(object parameter)
        {
            if (canExecute!=null)
            {
                return canExecute(parameter);
            }
            return true;
        }

        public void Execute(object parameter)
        {
            if (execute != null)
            {
                execute(parameter);
            }
        }

        public messengerCommands(Action<object> executeAction) : this(executeAction, null) { }
        public messengerCommands (Action<object> executeAction, Func<object, bool> canExecuteFunc)
        {
            canExecute = canExecuteFunc;
            execute = executeAction;

        }
        

    }
}
