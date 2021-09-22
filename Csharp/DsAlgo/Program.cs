using System;

namespace DsAlgo
{
    class Program
    {
        static void Main(string[] args)
        {
            HashTableAlgo hash = new HashTableAlgo();
            hash.Put(1,"one");
            hash.Put(2,"two");
            hash.Put(3,"three");
            hash.Put(4,"four");

            var v=hash.Get(3);
            Console.WriteLine(v);
        }
    }
}
