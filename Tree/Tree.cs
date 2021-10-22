using System;

namespace Tree
{
    public class Tree
    {
        class Node
        {
            public int value;
            public Node leftNode;
            public Node RightNode;
            public Node(int value)
            {
                this.value = value;
            }

            public override string ToString()
            {
                return this.value.ToString();
            }
        }

        private Node root;

        public void Insert(int value)
        {
            var node = new Node(value);
            if (root == null)
            {
                root = node;
                return;
            }

            var current = root;

            while (true)
            {
                if (current.value < value)
                {
                    if (current.RightNode == null)
                    {
                        current.RightNode = node;
                        break;
                    }
                    current = current.RightNode;
                }
                else
                {
                    if (current.leftNode == null)
                    {
                        current.leftNode = node;
                        break;
                    }
                    current = current.leftNode;
                }
            }

        }

        public bool Find(int value)
        {
            if (root == null)
            {
                System.Console.WriteLine("Empty Tree");
                return false;
            }

            var current = root;

            if (current.value == value)
                return true;

            while (current != null)
            {
                if (current.value < value)
                {
                    current = current.RightNode;
                }
                else if (current.value > value)
                {
                    current = current.leftNode;
                }
                else
                    return true;
            }

            return false;
        }

        private void PreDFS(Node root)
        {
            if (root == null)
                return;

            // root left right
            System.Console.WriteLine(root.value);
            PreDFS(root.leftNode);
            PreDFS(root.RightNode);
        }

        private void InDFS(Node root)
        {
            if (root == null)
                return;

            // left root right
            InDFS(root.leftNode);
            System.Console.WriteLine(root.value);
            InDFS(root.RightNode);
        }

        private void PostDFS(Node root)
        {
            if (root == null)
                return;

            // left right root
            PostDFS(root.leftNode);
            PostDFS(root.RightNode);
            System.Console.WriteLine(root.value);
        }

        public void Print()
        {
            System.Console.WriteLine("Pre-Order");
            PreDFS(root);
            System.Console.WriteLine();

            System.Console.WriteLine("In-Order");
            InDFS(root);
            System.Console.WriteLine();

            System.Console.WriteLine("Post-Order");
            PostDFS(root);
            System.Console.WriteLine();
        }

        public int Height()
        {
            return Height(root);
        }
        private int Height(Node node)
        {
            // assume as less then zero
            if (node == null)
            {
                return -1;
            }

            // System.Console.WriteLine(node.value);
            // asume as leaf node
            if (node.leftNode == null && node.RightNode == null)
            {
                return 0;
            }
            var left = Height(node.leftNode);
            if (node.leftNode != null)
            {
                System.Console.WriteLine($"node:{node.leftNode.value}, value- {left}");
            }
            var right = Height(node.RightNode);
            if (node.RightNode != null)
            {
                System.Console.WriteLine($"node:{node.RightNode.value}, value- {right}");
            }

            var r = 1 + Math.Max(left, right);
            // System.Console.WriteLine(r);
            return r;
        }

        public int MinValue()
        {
            return MinValue(root);
        }
        private int MinValue(Node node)
        {
            if (node.leftNode == null && node.RightNode == null)
            {
                return node.value;
            }
            if (node.leftNode == null && node.RightNode != null)
            {
                return node.RightNode.value;
            }else
            if (node.leftNode != null && node.RightNode == null)
            {
                return node.leftNode.value;
            }

            return Math.Min(Math.Min(MinValue(node.leftNode), MinValue(node.RightNode)), node.value);
        }
    }
}