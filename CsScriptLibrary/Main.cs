using System;
using System.CodeDom.Compiler;
using System.IO;
using System.Linq;
using System.Reflection;
using Microsoft.CSharp;

namespace CsScriptLibrary
{
    public static class Main
    {
        public static void Compile()
        {
            TextWriter t = new StreamWriter("fuck.txt");
            t.Write("FUCK");

            CSharpCodeProvider codeProvider = new CSharpCodeProvider();
            CompilerParameters parameters = new CompilerParameters
            {
                GenerateInMemory = true,
                GenerateExecutable = false,
                OutputAssembly = "CsScript"
            };

            AppDomain.CurrentDomain.GetAssemblies().ToList().ForEach(a => t.WriteLine(a.FullName));
        }
    }
}