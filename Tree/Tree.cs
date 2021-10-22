using System;
using System.Collections.Generic;

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
            // if (node.leftNode != null)
            // {
            //     System.Console.WriteLine($"node:{node.leftNode.value}, value- {left}");
            // }
            var right = Height(node.RightNode);
            // if (node.RightNode != null)
            // {
            //     System.Console.WriteLine($"node:{node.RightNode.value}, value- {right}");
            // }

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
            }
            else
            if (node.leftNode != null && node.RightNode == null)
            {
                return node.leftNode.value;
            }

            return Math.Min(Math.Min(MinValue(node.leftNode), MinValue(node.RightNode)), node.value);
        }

        public bool Equals(Tree other)
        {
            if (other == null)
            {
                return false;
            }
            return Equals(root, other.root);
        }
        private bool Equals(Node A, Node B)
        {
            if (A == null && B == null)
            {
                return true;
            }

            if (A != null && B != null)
            {
                return A.value == B.value &&
                    Equals(A.leftNode, B.leftNode) &&
                    Equals(A.RightNode, B.RightNode);
            }

            return false;
        }

        public void Swap()
        {
            var temp = root.leftNode;
            root.leftNode = root.RightNode;
            root.RightNode = temp;
        }
        public bool IsBinarySearchTree()
        {
            return IsBinarySearchTree(root, Int64.MinValue, Int64.MaxValue);
        }
        private bool IsBinarySearchTree(Node node, long min, long max)
        {
            if (node == null)
            {
                return true;
            }

            if (node.value < min || node.value > max)
            {
                return false;
            }

            return IsBinarySearchTree(node.leftNode, min, node.value - 1) &&
                    IsBinarySearchTree(node.RightNode, node.value + 1, max);
        }

        public void GetDistanceOfKth(int k)
        {
            // var list = new List<int>();
            GetDistanceOfKth(root, k);
        }
        private void GetDistanceOfKth(Node node, int k)
        {
            if (node == null)
            {
                return;
            }

            if (k == 0)
            {
                System.Console.WriteLine(node.value);
            }

            GetDistanceOfKth(node.leftNode, k - 1);
            GetDistanceOfKth(node.RightNode, k - 1);

            return;
        }

        public void GetLevelWiseTree()
        {
            var h = Height();

            for (int i = 0; i <= h; i++)
            {
                GetDistanceOfKth(i);
            }
        }

        public int CountLeafNode()
        {
            var counter = 0;
            CountLeafNode(root, ref counter);
            return counter;
        }
        private void CountLeafNode(Node node, ref int counter)
        {
            if (node == null)
            {
                return;
            }

            if (node.leftNode == null && node.RightNode == null)
            {
                counter++;
            }

            CountLeafNode(node.leftNode, ref counter);
            CountLeafNode(node.RightNode, ref counter);
        }

        public int CountLeafNodeOpt()
        {
            return CountLeafNodeOpt(root, 0);
        }
        private int CountLeafNodeOpt(Node node, int counter)
        {
            if (node == null)
            {
                return 0;
            }

            if (node.leftNode == null && node.RightNode == null)
            {
                return 1;
            }

            counter += CountLeafNodeOpt(node.leftNode, counter);
            counter += CountLeafNodeOpt(node.RightNode, counter);
            return counter;
        }
    }
}