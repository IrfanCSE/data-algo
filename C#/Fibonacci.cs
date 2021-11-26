using System.Collections.Generic;

namespace C_Sharp
{
    public class Fibonacci
    {
        public static Dictionary<long?, ulong?> lookUp;
        static Fibonacci()
        {
            lookUp = new Dictionary<long?, ulong?>();
        }

        public static ulong Fib(int n)
        {
            // 2-5-7-12-19-31....

            // skip calculation if its exist in lookUp table
            if (lookUp.ContainsKey(n))
                return lookUp[n].Value;

            if (n == 0)
            {
                // add in lookUp table
                lookUp.Add(0, 2);
                return 2;
            }

            if (n == 1)
            {
                // add in lookUp table
                lookUp.Add(1, 5);
                return 5;
            }

            // calculation
            var Value = Fib(n - 2) + Fib(n - 1);
            
            // add in lookUp table
            lookUp.Add(n, Value);
            
            return Value;
        }
    }
}