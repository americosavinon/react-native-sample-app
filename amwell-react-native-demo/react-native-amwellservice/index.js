import { NativeModules, 
    requireNativeComponent,
} from "react-native";

const { Amwellservice } = NativeModules;

const RNCounterView = requireNativeComponent("CounterView");
const RNAmwellView = requireNativeComponent("AmwellView");

export { Amwellservice, RNCounterView, RNAmwellView };
