using System;
using System.Linq;
using Engine;

namespace Test
{
    public class TestScript : Script
    {
        public override void Start()
        {
            Console.WriteLine("TestScript started!");
            Unit.rotation = 1f;
            Unit.speed = 10;
            Unit.direction = new Vector2(1, 3);
        }

        public override void Update()
        {

        }
    }
}