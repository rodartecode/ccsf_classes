using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using CNIT134MVC.Models;
using System.Net;
using Newtonsoft.Json;

namespace CNIT134MVC.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Events()
        {
            var webClient = new WebClient();
            var jsonData = webClient.DownloadString(@"https://hills.ccsf.edu/~jrodarte/CNIT134/events.json");
            var EventList = JsonConvert.DeserializeObject<EventsList>(jsonData);
            return View(EventList);
        }


        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
