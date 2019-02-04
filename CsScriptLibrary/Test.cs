using System;
using System.Linq;

namespace Fuck
{
    public static class Test
    {
        public static void TestFunc()
        {
            foreach (var ass in AppDomain.CurrentDomain.GetAssemblies().First(i => i.GetName().Name == "ManagedCppLibrary").GetTypes().Select(t => t.Namespace).Distinct())
            {
                var d = typeof(ManagedCppLibrary.Compiler);
                Console.WriteLine(ass);
            }
        }
    }
}