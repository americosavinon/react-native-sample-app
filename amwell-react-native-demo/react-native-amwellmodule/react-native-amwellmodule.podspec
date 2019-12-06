require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-amwellmodule"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.description  = <<-DESC
                  react-native-amwellmodule
                   DESC
  s.homepage     = "https://github.com/github_account/react-native-amwellmodule"
  s.license      = "MIT"
  # s.license    = { :type => "MIT", :file => "FILE_LICENSE" }
  s.authors      = { "Your Name" => "yourname@email.com" }
  s.platforms    = { :ios => "9.0" }
  s.source       = { :git => "https://github.com/github_account/react-native-amwellmodule.git", :tag => "#{s.version}" }

  s.source_files = "ios/src/**/*.{h,m,swift}"
  s.requires_arc = true

  s.swift_versions = "5.0"
  s.vendored_frameworks = "ios/Frameworks/AWSDK.framework","ios/Frameworks/WebRTC.framework"

  s.dependency "React", "0.61.5"
  # ...
  # s.dependency "..."
end

