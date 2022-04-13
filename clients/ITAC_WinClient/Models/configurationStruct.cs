using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ITAC_WinClient.Models
{
    internal struct ConfigurationStruct
    {
        public string host { get; set; }
        public int port { get; set; }
        public int hystoryExpirationDate { get; set; }
        public string pathFile { get; set; }
        public string  nameConfig { get; set; }

    }
}
