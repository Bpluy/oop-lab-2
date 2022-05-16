using l4.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace MobileApp
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        protected override void OnAppearing()
        {
            string dbPath = DependencyService.Get<IPath>().GetDatabasePath(App.DBFILENAME);
            using (CarContext db = new CarContext(dbPath))
            {
                carList.ItemsSource = db.Cars.ToList();
            }
            base.OnAppearing();
        }

        private async void OnItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            Car selectedCar = (Car)e.SelectedItem;
            CarPage carPage = new CarPage();
            carPage.BindingContext = selectedCar;
            await Navigation.PushAsync(carPage);
        }

        private async void AddCar(object sender, EventArgs e)
        {
            Car car = new Car();
            CarPage carPage = new CarPage();
            carPage.BindingContext = car;
            await Navigation.PushAsync(carPage);
        }
    }
}
