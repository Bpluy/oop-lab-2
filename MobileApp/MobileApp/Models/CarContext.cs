using Microsoft.EntityFrameworkCore;

namespace l4.Models
{
    public class CarContext : DbContext
    {
        private string _databasePath;

        public DbSet<Car> Cars { get; set; }

        public CarContext(string databasePath)
        {
            _databasePath = databasePath;
        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlite($"Filename={_databasePath}");
        }
    }
}
