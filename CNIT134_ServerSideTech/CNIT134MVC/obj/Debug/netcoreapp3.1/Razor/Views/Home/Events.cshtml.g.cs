#pragma checksum "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\Home\Events.cshtml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "6e10b40354f98fbb6d5b4ee9a6a5b1f6ed574d2b"
// <auto-generated/>
#pragma warning disable 1591
[assembly: global::Microsoft.AspNetCore.Razor.Hosting.RazorCompiledItemAttribute(typeof(AspNetCore.Views_Home_Events), @"mvc.1.0.view", @"/Views/Home/Events.cshtml")]
namespace AspNetCore
{
    #line hidden
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.Rendering;
    using Microsoft.AspNetCore.Mvc.ViewFeatures;
#nullable restore
#line 1 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\_ViewImports.cshtml"
using CNIT134MVC;

#line default
#line hidden
#nullable disable
#nullable restore
#line 2 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\_ViewImports.cshtml"
using CNIT134MVC.Models;

#line default
#line hidden
#nullable disable
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"6e10b40354f98fbb6d5b4ee9a6a5b1f6ed574d2b", @"/Views/Home/Events.cshtml")]
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"238205576d889d2ba1c8fe1e508d789cb61f2f4d", @"/Views/_ViewImports.cshtml")]
    public class Views_Home_Events : global::Microsoft.AspNetCore.Mvc.Razor.RazorPage<EventsList>
    {
        #pragma warning disable 1998
        public async override global::System.Threading.Tasks.Task ExecuteAsync()
        {
            WriteLiteral("\r\n");
#nullable restore
#line 3 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\Home\Events.cshtml"
  
    ViewData["Title"] = "Events";

#line default
#line hidden
#nullable disable
            WriteLiteral("\r\n<h1>");
#nullable restore
#line 7 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\Home\Events.cshtml"
Write(ViewData["Title"]);

#line default
#line hidden
#nullable disable
            WriteLiteral(@"</h1>
<h2 class=""display-4"">ASP.NET Adventure Seminar Events!</h2>
<p>We are very excited to to able to host all of you for this exciting event. All of the following events are free to attend for anybody who would like to participate. </p>
<p>The following events will be available to attend. Please arrive early, as sitting will be limited.   </p>
<ul>
");
#nullable restore
#line 12 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\Home\Events.cshtml"
     foreach (var item in Model.Events)
    {

#line default
#line hidden
#nullable disable
            WriteLiteral("        <li>\r\n");
#nullable restore
#line 15 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\Home\Events.cshtml"
              
                var listItem = item.Title + " - Room: " + item.Location + " - " + item.Time;

                

#line default
#line hidden
#nullable disable
#nullable restore
#line 18 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\Home\Events.cshtml"
           Write(Html.DisplayFor(modelItem => listItem));

#line default
#line hidden
#nullable disable
            WriteLiteral("\r\n        </li>\r\n");
#nullable restore
#line 22 "C:\Users\Jesse\Code\ccsf_classes\CNIT134_ServerSideTech\CNIT134MVC\Views\Home\Events.cshtml"
    }

#line default
#line hidden
#nullable disable
            WriteLiteral("</ul>");
        }
        #pragma warning restore 1998
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.ViewFeatures.IModelExpressionProvider ModelExpressionProvider { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IUrlHelper Url { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IViewComponentHelper Component { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IJsonHelper Json { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IHtmlHelper<EventsList> Html { get; private set; }
    }
}
#pragma warning restore 1591
