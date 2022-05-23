using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ITACmessendgerMVVM_wpf_.Models
{
    internal class messegeJson
    {
        public string  messegeJSON { get; set; }
        public messegeJson (object obj)
        {
            messegeJSON = createMessegeJson(obj);
        }

        private string createMessegeJson(object obj)
        {
            Type tp = obj.GetType();
            FieldInfo[] fields = tp.GetFields();
            PropertyInfo[] properties = tp.GetProperties();
            var messege = new StringBuilder("{\n");
            foreach (var p in properties)
            {
                var value = p.GetValue(obj, null);
                if (value == null)
                {
                    value = "null";
                }
                messege.Append("\"" + p.Name.ToString() + "\":\"" + value + "\",\n");
            }
            messege.Append("}");
            return messege.ToString();
        }
    }
}
