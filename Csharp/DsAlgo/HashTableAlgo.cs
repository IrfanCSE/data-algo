using System.Collections.Generic;

namespace DsAlgo
{
    public class HashTableAlgo
    {
        private class Entry
        {
            public Entry(int key, string value)
            {
                Key = key;
                Value = value;
            }

            public int Key { get; set; }
            public string Value { get; set; }
        }

        private List<Entry>[] item;
        public HashTableAlgo()
        {
            item = new List<Entry>[5];
        }

        private int Hash(int key)
        {
            return key % item.Length;
        }

        public void Put(int key, string value)
        {
            int index = Hash(key);
            if (item[index] == null)
            {
                item[index] = new List<Entry>();
            }
            item[index].Add(new Entry(key, value));
        }

        public string Get(int key)
        {
            int index = key % item.Length;
            foreach (var i in item[index])
            {
                if (i.Key == key) return i.Value;
            }
            return null;
        }
    }
}