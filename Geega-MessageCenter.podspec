

Pod::Spec.new do |spec|

  spec.name         = "Geega-MessageCenter"
  spec.version      = "0.0.1"
  spec.summary      = "Geega-MessageCenter"
  spec.homepage     = "https://github.com/YBKMingMing/Geega-MessageCenter"
  spec.license      = { :type => "MIT", :file => "LICENSE" } 
  spec.author             = "YBKMingMing"
  spec.platform     = :ios, "10.0"
  spec.source       = { :git => "https://github.com/YBKMingMing/Geega-MessageCenter.git", :tag => "#{s.version}"  }


spec.subspec 'Source' do |source|
	source.resources ="MessageCenter/MessageCenter/Sources/Resources/**/*.bundle"
    source.source_files = "MessageCenter/MessageCenter/Sources/**/*.{h,m,mm}"
 end 

spec.subspec 'Framework' do |framework|
    framework.resources ="MessageCenter/MessageCenter/Sources/Resources/**/*.bundle"
    framework.vendored_frameworks = "MessageCenter/MessageCenter/Framework/MessageCenterSDK.framework"
  end

spec.ios.dependency "JPush"

end
