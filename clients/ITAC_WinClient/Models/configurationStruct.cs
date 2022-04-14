using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ITAC_WinClient.Models
{
    public struct ConfigurationStruct
    {
        public string host { get; set; }
        public string port { get; set; }
        public string hystoryExpirationDate { get; set; }
        public string pathFile { get; set; }
        public string  nameConfig { get; set; }

    }
}
