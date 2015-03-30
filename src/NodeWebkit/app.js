var ngui = require('nw.gui');
var appWindow = ngui.Window.get();

initialize();
function initialize(){
  appWindow.maximize();
      console.info("App Initialized");
}
