using Microsoft.EntityFrameworkCore;

namespace _3.Models
{
    public class CarContext : DbContext
    {
        public DbSet<Car> Cars { get; set; }
        public DbSet<Order> Orders { get; set; }

        public CarContext(DbContextOptions<CarContext> options) : base(options)
        {
            Database.EnsureCreated();
        }
    }
}
