using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Microsoft.VisualStudio.Coverage.Analysis;

namespace coverage
{
    class Program
    {
        static void Main(string[] args)
        {
            using (CoverageInfo info = CoverageInfo.CreateFromFile(
                "PATH_OF_YOUR_*.coverage_FILE",
                new string[] { @"DIRECTORY_OF_YOUR_DLL_OR_EXE" },
                new string[] { }))
            {
                CoverageDS data = info.BuildDataSet();
                data.WriteXml("converted.coveragexml");
            }
        }
    }
}
