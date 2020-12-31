Pod::Spec.new do |spec|
  spec.name         = "BTSource"
  spec.version      = "0.0.2"
  spec.summary      = "A short description of BaiDuRTC."
  spec.description  = <<-DESC
                        BaiDuRTC
                   DESC

  spec.homepage     = "https://github.com/GasparChu/BTSource"
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.author             = { "GasparChu" => "598176910@qq.com" }
  spec.ios.deployment_target = '10.0'
  spec.source       = { :git => "https://github.com/GasparChu/BTSource.git", :tag => spec.version.to_s }
  # spec.source_files  = "BaiDuRTC", "BDRTC/Libs/*"

  spec.frameworks  = "VideoToolbox", "GLKit"

  spec.library   = "c++"
  # spec.libraries = "iconv", "xml2"

  spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"

  spec.ios.vendored_libraries = ["Libs/libcrypto.a", "Libs/libssl.a"]

  spec.ios.vendored_frameworks = "Libs/SocketRocket/SocketRocket/SocketRocket.framework", "Framework/BaiduRtcRoom.framework"
  spec.ios.source_files = "Libs/SocketRocket/SocketRocket.binspec.json", "Libs/SocketRocket/SocketRocket.md5"

end
