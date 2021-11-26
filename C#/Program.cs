
using System.Linq;
using System.Collections.Generic;
using System;
using C_Sharp;

namespace Algorithm
{
    class Program
    {
        static int Main()
        {
            var n = Convert.ToInt32(Console.ReadLine());
            var result = Fibonacci.Fib(n);
            System.Console.WriteLine(result);
            return 0;
        }
        // static int Main()
        // {
        //     var l1 = new LinkedList<long>();
        //     l1.AddLast(new LinkedListNode<long>(1));
        //     l1.AddLast(new LinkedListNode<long>(3));

        //     var l2 = new LinkedList<long>();
        //     l2.AddLast(new LinkedListNode<long>(2));
        //     l2.AddLast(new LinkedListNode<long>(4));

        //     var l = MergeLL.Merge(l1.First, l2.First);
        //     var it = l.First;
        //     while (it!=null)
        //     {
        //         Console.WriteLine(it.Value);
        //         it = it.Next;
        //     }
        //     return 0;
        // }
    }
}
