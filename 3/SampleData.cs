using System.Linq;
using _3.Models;

namespace _3
{
    public class SampleData
    {
        public static void Initialize(CarContext context)
        {
            if (!context.Cars.Any())
            {
                context.Cars.AddRange(
                    new Car
                    {
                        Brand = "BMW",
                        Name = "X5",
                        Power = 231,
                        Price = 8960000
                    },
                    new Car
                    {
                        Brand = "Mercedes",
                        Name = "C180",
                        Power = 150,
                        Price = 2649800
                    },
                    new Car
                    {
                        Brand = "LADA",
                        Name = "Priora",
                        Power = 106,
                        Price = 670000
                    },
                    new Car
                    {
                        Brand = "BMW",
                        Name = "540i",
                        Power = 340,
                        Price = 8100000
                    },                    
                    new Car
                    {
                        Brand = "LADA",
                        Name = "Vesta",
                        Power = 122,
                        Price = 1100000
                    }
                );
                context.SaveChanges();
            }
        }
    }
}
