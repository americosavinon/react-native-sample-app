import { NativeModules, requireNativeComponent } from "react-native";

const { Amwellservice } = NativeModules;

const COMPONENT_NAME = "CounterView";
const RNCounterView = requireNativeComponent(COMPONENT_NAME);

export { Amwellservice, RNCounterView };
