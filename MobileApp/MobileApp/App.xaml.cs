using l4.Models;
using Microsoft.EntityFrameworkCore;
using Xamarin.Forms;

namespace MobileApp
{
    public partial class App : Application
    {
        public const string DBFILENAME = "carsapp.db";
        public App()
        {
            InitializeComponent();

            string dbPath = DependencyService.Get<IPath>().GetDatabasePath(DBFILENAME);
            using (var db = new CarContext(dbPath))
            {
                db.Database.EnsureCreated();
                db.Cars.Load();
                if (db.Cars.Local.Count == 0)
                {
                    db.Cars.Add(
                        new Car
                        {
                            Brand = "BMW",
                            Name = "X5",
                            Power = 231,
                            Price = 8960000
                        });
                    db.Cars.Add(
                        new Car
                        {
                            Brand = "Mercedes",
                            Name = "C180",
                            Power = 150,
                            Price = 2649800
                        });
                    db.Cars.Add(
                        new Car
                        {
                            Brand = "BMW",
                            Name = "540i",
                            Power = 340,
                            Price = 8100000
                        });
                    db.Cars.Add(
                        new Car
                        {
                            Brand = "LADA",
                            Name = "Priora",
                            Power = 106,
                            Price = 670000
                        });
                    db.Cars.Add(
                       new Car
                       {
                           Brand = "LADA",
                           Name = "Vesta",
                           Power = 122,
                           Price = 1100000
                       });
                    db.SaveChanges();
                }
            }
            MainPage = new NavigationPage(new MainPage());
        }

        protected override void OnStart()
        {
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }
}
