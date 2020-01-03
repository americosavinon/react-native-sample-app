import { AppRegistry, YellowBox} from "react-native";
import App from "./src/app.component";
import { name as appName } from "./app.json";

// YellowBox.ignoreWarnings([
//     'RCTBridge',
//     'State updates',
//   ]);

AppRegistry.registerComponent(appName, () => App);
