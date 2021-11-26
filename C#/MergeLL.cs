using System;
using System.Collections.Generic;

namespace Algorithm
{
    public static class MergeLL
    {
        public static LinkedList<long> Merge(LinkedListNode<long> l1, LinkedListNode<long> l2)
        {
            // assuming execute for positive Value.
            var list = new LinkedList<long>();

            // loop

            while (l1 != null && l2 != null)
            {
                // if l1 is null then pass l2 reversed l1
                if (l1 == null)
                {
                    list.AddLast(l2);
                    l2 = l2.Next;
                    continue;
                }
                if (l2 == null)
                {
                    list.AddLast(l1);
                    l1 = l1.Next;
                    continue;
                }
                //check l1<l2 pass l1 or l2<l1 pass l2
                if (l1.Value < l2.Value)
                {
                    list.AddLast(l1);
                    l1 = l1.Next;
                    continue;
                }
                if (l1.Value > l2.Value)
                {
                    list.AddLast(l2);
                    l2 = l2.Next;
                    continue;
                }
            }

            return list;
        }
    }
}