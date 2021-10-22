using System;

namespace Tree
{
    class Program
    {
        static void Main(string[] args)
        {
            var tree = new Tree();

            // [10, 5, 15, 6, 1, 8, 12, 18, 17]

            tree.Insert(10);
            tree.Insert(5);
            tree.Insert(15);
            tree.Insert(6);
            tree.Insert(1);
            tree.Insert(8);
            tree.Insert(12);
            tree.Insert(18);
            tree.Insert(17);

            // var result = tree.Find(111);

            // tree.Print();

            Console.WriteLine(tree.MinValue());

        }
    }
}
