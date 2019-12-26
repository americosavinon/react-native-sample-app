require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-amwellservice"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.description  = <<-DESC
                  react-native-amwellservice
                   DESC
  s.homepage     = "https://github.com/github_account/react-native-amwellservice"
  s.license      = "MIT"
  # s.license    = { :type => "MIT", :file => "FILE_LICENSE" }
  s.authors      = { "Your Name" => "yourname@email.com" }
  s.platforms    = { :ios => "13.0" }
  s.source       = { :git => "https://github.com/github_account/react-native-amwellservice.git", :tag => "#{s.version}" }

  s.source_files = "ios/src/**/*.{h,m,swift}"
  s.requires_arc = true

  s.swift_versions = "5.0"
  s.vendored_frameworks = "ios/Frameworks/AWSDK.framework","ios/Frameworks/WebRTC.framework"

  s.dependency "React"
  # ...
  # s.dependency "..."
end

