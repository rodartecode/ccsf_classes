# ASP.NET ViewState

Jesse Rodarte, CNIT 134

Jan 22, 2020

## Description

The ViewState in .NET is a function that lets you save retrieve state between page reloads. Normally whenever a page is reloaded an entire new page is generated which replaces the current page. This usually means that any forms will be set to their default values. Using ViewState you can save info and automatically update controls or forms when a page reloads. It is enabled by default and can be used in ASP web forms very easily to both set and get values for the page.

The data is stored in a "dictionary" which is a collection object that uses key/value pairs to set and get items. To access a value you need to use a key. The usage is similar to a regular array using square brackets. The difference is that instead of passing an int value for the item, you pass a String key. If a value exists with that key, the value will be returned, otherwise it will return a null value. One disadvantage though, is that these methods are only available on desktops which means that on mobile devices they wouldn't work.

---

### Code Sample

The following code is a simple example of how you can use ViewState on an ASP web form. This example lets a user enter a text string, clears the text field, and fills it again with the saved value using a button.

> TestApp.aspx

```HTML
<%@ page language="C#" autoeventwireup="true" codebehind="TestApp.aspx.cs"
    inherits="TestApp.__default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <form id="form1" runat="server">
      <div>
          Text:<asp:textbox id="TextBox" runat="server"></asp:textbox>
          <br />
          <asp:button id="SetButton" runat="server" onclick="Set" text="Submit" />
          <asp:button id="GetButton" runat="server" onclick="Get" text="Restore" />
      </div>
    </form>
</asp:Content>
```

> TestApp.aspx.cs

```Java
protected void Set(object sender, EventArgs e)
{
    ViewState["text"] = TextBox.Text;
    TextBox.Text = string.Empty;
}
protected void Get(object sender, EventArgs e)
{
    TextBox.Text = ViewState["text"];
}
```

---

#### Citations

- [C-SharpCorner](https://www.c-sharpcorner.com/UploadFile/225740/what-is-view-state-and-how-it-works-in-Asp-Net53/)
- [MSDN](https://docs.microsoft.com/en-us/dotnet/api/system.web.ui.control.viewstate?view=netframework-4.8)
- [StackOverflow](https://stackoverflow.com/questions/2652271/what-is-the-viewstate-in-asp-net)
