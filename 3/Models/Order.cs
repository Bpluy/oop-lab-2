namespace _3.Models
{
    public class Order
    {
        public int OrderId { get; set; }
        public string BuyerName { get; set; }
        public string BuyerAddress { get; set; }
        public string BuyerPhoneNumber { get; set; }

        public int CarId { get; set; }
        public Car Car { get; set; }
    }
}
