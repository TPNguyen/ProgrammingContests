using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Globalization;

namespace Codeforces
{
	class Program
	{
		public void Solve ()
		{
			int n = io.NextInt ();

			var cnt = new int[20000];

			for (int i = 0; i < n; ++i) {
				int x = io.NextInt ();
				cnt [x]++;
			}

			for (int i = 1; i < 20000; ++i)
				cnt [i] += cnt [i - 1];

			int answer = n;

			for (int i = 1; i <= 5000; ++i) {
				answer = Math.Min(answer, n - (cnt[2 * i] - cnt[i - 1]));
			}

			io.PrintLine (answer);
		}

        #region Program

        private readonly MyIo io;

        public Program(MyIo io)
        {
            this.io = io;
        }

        public static void Main(string[] args)
        {
            using (MyIo io = new MyIo(new StreamReader("input.txt"), new StreamWriter("output.txt")))
            {
                new Program(io).Solve();
            }
        }

        #endregion
    }

    #region MyIo

    internal class MyIo : IDisposable
    {
        private readonly TextReader reader;
        private readonly TextWriter writer;

        private string[] tokens;
        private int pointer;

		public MyIo ()
			: this(Console.In, Console.Out)
		{
		}

		public MyIo (TextReader reader, TextWriter writer)
		{
			this.reader = reader;
			this.writer = writer;
		}
 
        public string NextLine()
        {
            try
            {
                return reader.ReadLine();
            }
            catch (IOException)
            {
                return null;
            }
        }

        public string NextString()
        {
            try
            {
                while (tokens == null || pointer >= tokens.Length)
                {
                    tokens = NextLine().Split(new char[] { &#39; &#39;, &#39;\t&#39; }, StringSplitOptions.RemoveEmptyEntries);
                    pointer = 0;
                }
                return tokens[pointer++];
            }
            catch (IOException)
            {
                return null;
            }
        }

        public int NextInt()
        {
            return int.Parse (NextString());
        }

        public long NextLong()
        {
			return long.Parse (NextString());
        }

		public double NextDouble()
        {
			return double.Parse (NextString());
        }

        public T Next<T>()
        {
            return (T)Convert.ChangeType(NextString(), typeof(T));
        }

        public IEnumerable<T> NextSeq<T>(int n)
        {
			for (int i = 0; i < n; i++)
				yield return Next<T>();
        }

        public void Print(string format, params object[] args)
        {
            writer.Write(string.Format(CultureInfo.InvariantCulture, format, args));
        }

        public void PrintLine(string format, params object[] args)
        {
            Print(format, args);
            writer.WriteLine();
        }

        public void Print<T>(T o)
        {
            writer.Write(o);
        }

        public void PrintLine<T>(T o)
        {
            writer.WriteLine(o);
        }

		public void PrintLine()
        {
            writer.WriteLine();
        }

        public void Close()
        {
            reader.Close();
            writer.Close();
        }

        void IDisposable.Dispose()
        {
            Close();
        }
    }

    #endregion
}
