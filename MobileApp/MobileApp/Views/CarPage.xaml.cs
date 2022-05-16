using l4.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace MobileApp
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class CarPage : ContentPage
    {
        string dbPath;
        public CarPage()
        {
            InitializeComponent();
            dbPath = DependencyService.Get<IPath>().GetDatabasePath(App.DBFILENAME);
        }
        private void SaveCar(object sender,EventArgs e)
        {
            var car = (Car)BindingContext;
            if(!(String.IsNullOrEmpty(car.Brand)
                && String.IsNullOrEmpty(car.Name) 
                && String.IsNullOrEmpty(car.Power.ToString())
                && String.IsNullOrEmpty(car.Price.ToString())))
            {
                using (CarContext db = new CarContext(dbPath))
                {
                    if (car.Id == 0)
                        db.Cars.Add(car);
                    else
                        db.Cars.Update(car);
                    db.SaveChanges();
                }
                this.Navigation.PopAsync();
            }
        }
        private void DeleteCar(object sender, EventArgs e)
        {
            var car = (Car)BindingContext;
            using (CarContext db = new CarContext(dbPath))
            {
                db.Cars.Remove(car);
                db.SaveChanges();
            }
            this.Navigation.PopAsync();
        }
    }
}